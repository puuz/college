<?php

// personal database I created for this assignment
$servername = 'sql5.freemysqlhosting.net';
$database = 'sql5668581';
$username = 'sql5668581';
$password = 'KSfzytviUN';

$user = $_POST['username'];
$pass = $_POST['password'];
$cpass = $_POST['confirm-password'];

$title = $_POST['title-input'];
$date = $_POST['date-input'];
$description = $_POST['description-input'];

$error = '';

// establish mysql connection
$conn = mysqli_connect($servername, $username, $password, $database);
if (!$conn) {
    $error = 'There was an error connecting to the database.';
    die ('Connection Failed: ' . mysqli_connect_error());
}

//declare variables so can use globally in php file
$sql = '';
$results = '';
$row = '';
$notes = array();
$newAccount = false;
$score = 0;

//don't use return otherwise the rest of the content won't be posted

// post requests when adding a note
if ($title && $date && $description && $user) {
    // insert the new data for the added note
    $sql = "INSERT INTO notes(username, title, date, description) VALUES('$user', '$title', '$date', '$description');";
    mysqli_query($conn, $sql);
    // re query to post each note under the user that just added the most recent note
    $sql = "SELECT title, date, description FROM notes WHERE username = '$user';";
    $results = mysqli_query($conn, $sql);
    while($row = mysqli_fetch_assoc($results)) {
        $score = $score + 1;
        array_push($notes, $row);
    }
    if ($score == 1) {
        $sql = "INSERT INTO scores(username, score) VALUES('$user', $score);";
        mysqli_query($conn, $sql);
    } else {
        $sql = "UPDATE scores SET score = $score WHERE username = '$user'";
        mysqli_query($conn, $sql);
    }
    mysqli_close($conn);
    // set cookie to remember user for 3 days
    setcookie("username", "$user", time() + 259200);
    header("Location: todo.php");
} else {
    // confirm pass definition means it's a new user
    if ($cpass) {
        $sql = "SELECT username FROM users WHERE username = '$user';";
        $results = mysqli_query($conn, $sql);
        $row = mysqli_fetch_assoc($results);
        // make sure the user they used doesn't already exist, because it would cause issues with note queries
        if ($row['username']) {
            $error = "There's already someone with that username.";
            mysqli_close($conn);
        } else {
            // add user to the users table
            $sql = "INSERT INTO users(username, password) VALUES('$user', '$pass');";
            mysqli_query($conn, $sql);
            $newAccount = true;
            mysqli_close($conn);
        }
    } else {
        // when redirecting after post request of added note, cookies are used to remember who user is
        if (!$user) $user = $_COOKIE['username'];
        // existing user so just find if their password matches and select their notes information
        $sql = "SELECT password FROM users WHERE username = '$user';";
        $results = mysqli_query($conn, $sql);
        $row = mysqli_fetch_assoc($results);
        if ($row['password']) {
            //$user wouldn't be defined if this is a sign up process because no cookie would be set
            if ($pass != $row['password'] && !$user) {
                $error = "The password you entered doesn't match the username you entered.";
            } else {
                $sql = "SELECT title, date, description FROM notes WHERE username = '$user';";
                $results = mysqli_query($conn, $sql);
                while($row = mysqli_fetch_assoc($results)) {
                    array_push($notes, $row);
                }
                $sql = "SELECT score FROM scores WHERE username = '$user';";
                $results = mysqli_query($conn, $sql);
                $row = mysqli_fetch_assoc($results);
                $score = $row['score'];
            }
            mysqli_close($conn);
        } else {
            if (!$user) $error = "You're cookies expired please login again.";
            $error = "The username you entered doesn't exist.";
            mysqli_close($conn);
        }
    }
}
?>

<!DOCTYPE html>
<html lang="en">
    <head>
        <meta charset="utf-8">
        <title>To Do</title>
        <link href="todo.css" rel="stylesheet" type="text/css">
    </head>
    <body>
        <div class="background">
            <?php
            // in case there was any errors when quering the database output error and direct back to login
            if ($error) {
            ?>
                <div class="error-background">
                    <div class="error">
                        <span><?=$error?></span>
                        <a class="goback" href="login.html">Go back to login</a>
                    </div>
                </div>
            <?php
            } else {
            ?>
                <div class="header">
                    <span><?=$user?> (<?=$score?> note(s))</span>
                    <a href="login.html">Logout</a>
                </div>
                <div class="body">
            <?php
                // if it isn't a new account there could be existing notes so
                // so display each one with a for loop
                if (!$newAccount) {
                    foreach($notes as $note) {
            ?>
                        <div class="note">
                            <div class="note-title-container">
                                <span class="note-title"><?=$note['title']?></span>
                                <span class="note-date"><?=$note['date']?></span>
                            </div>
                            <span><?=$note['description']?></span>
                        </div>
            <?php
                    }
                }
            ?>
                </div>
                <form id="footer" action="todo.php" method="POST">
                    <div class="footer-top">
                        <input name="username" type="hidden" value="<?=$user?>">
                        <input class="note-input" id="title-input" name="title-input" type="text" maxlength="50" placeholder="Type title here...">
                        <input class="note-input" id="date-input" name="date-input" type="text" maxlength="20" placeholder="Type date here...">
                    </div>
                    <div class="footer-bottom">
                        <textarea class="note-input" id="description-input" name="description-input" oninput="descInputAction()" rows="1" maxlength="1000" placeholder="Type description here..."></textarea>
                        <button type="button" class="add-note" onclick="addNote()">Add Note</button>
                    </div>
                </form>
            <?php
            }
            ?>
        </div>
        <script>
            const dateRegex = /[0-9]{2}\/[0-9]{2}\/[0-9]{2} [0-1][0-9]:[0-5][0-9]:[0-5][0-9] (AM|PM)/;
            const titleInput = document.getElementById('title-input');
            const dateInput = document.getElementById('date-input');
            const descInput = document.getElementById('description-input');
            const footer = document.getElementById('footer');
            function addNote() {
                // error handling for adding notes
                if (!titleInput.value || titleInput.value.length > 50) {
                    alert('Title needs to be 1 to 50 characters long');
                    return;
                }
                if (!dateInput.value || !dateRegex.test(dateInput.value)) {
                    alert('Date needs to be exactly in this format 00/00/00 00:00:00 AM/PM');
                    return;
                }
                if (!descInput.value || descInput.value.length > 1000) {
                    alert('Description needs to be 1 to 1000 characters long');
                    return;
                }
                // ' won't work in sql query so needs escape key for each '
                titleInput.value = titleInput.value.replace("'", "\\'");
                dateInput.value = dateInput.value.replace("'", "\\'");
                descInput.value = descInput.value.replace("'", "\\'");
                footer.submit();
                return;
            }
            // dynamic expanding text box
            function descInputAction() {
                descInput.style.height = 'auto';
                descInput.style.height = (descInput.scrollHeight - 20) + 'px';
            }
        </script>
    </body>
</html>