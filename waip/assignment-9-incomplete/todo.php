<?php

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

$conn = mysqli_connect($servername, $username, $password, $database);
if (!$conn) {
    $error = 'There was an error connecting to the database.';
    die ('Connection Failed: ' . mysqli_connect_error());
}

$sql = '';
$results = '';
$row = '';
$notes = array();
$newAccount = false;

if ($title && $date && $description && $user) {
    $sql = "INSERT INTO notes(username, title, date, description) values('$user', '$title', '$date', '$description');";
    mysqli_query($conn, $sql);
    $sql = "SELECT title, date, description FROM notes WHERE username = $user";
    $result = mysqli_query($conn, $sql);
    while($row = mysqli_fetch_assoc($results)) {
        array_push($notes, $row);
    }
    mysqli_close($conn);
} else {
    if ($cpass) {
        $sql = "SELECT username FROM users WHERE username = '$user'";
        $results = mysqli_query($conn, $sql);
        $row = mysqli_fetch_assoc($results);
        if ($row['username']) {
            $error = "There's already someone with that username.";
            mysqli_close($conn);
        } else {
            $sql = "INSERT INTO users(username, password) values('$user', '$pass');";
            mysqli_query($conn, $sql);
            $newAccount = true;
            mysqli_close($conn);
        }
    } else {
        $sql = "SELECT password FROM users WHERE username = '$user'";
        $result = mysqli_query($conn, $sql);
        $row = mysqli_fetch_assoc($results);
        
        if ($row['password']) {
            if ($pass != $row['password']) {
                $error = "The password you entered doesn't match the username you entered.";
                mysqli_close($conn);
            } else {
                $sql = "SELECT title, date, description FROM notes WHERE username = $user";
                $result = mysqli_query($conn, $sql);
                while($row = mysqli_fetch_assoc($results)) {
                    array_push($notes, $row);
                }
            }
        } else {
            $error = "The username you entered doesn't exist.";
        }
        
        mysqli_close($conn);
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
            if ($error) {
            ?>
                <div class="error">
                    <span><?=$error?></span>
                    <a class="goback" href="login.html">Go back to login</a>
                </div>
            <?php
            } else {
            ?>
                <div class="header">
                    <span><?=$user?></span>
                    <a href="login.html">Logout</a>
                </div>
                <div class="body">
            <?php
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
            }
            ?>
                </div>
                <form id="footer" action="todo.php" method="POST">
                    <div class="footer-top">
                        <input name="username" type="hidden" value="<?=$user?>">
                        <input class="note-input" id="title-input" name="title-input" type="text" maxlength="20" placeholder="Type title here...">
                        <input class="note-input" id="date-input" name="date-input" type="text" maxlength="8" placeholder="Type date here...">
                    </div>
                    <div class="footer-bottom">
                        <textarea class="note-input" id="description-input" name="description-input" oninput="descInputAction()" rows="1" maxlength="1000" placeholder="Type description here..."></textarea>
                        <button class="add-note" onclick="addNote()">Add Note</button>
                    </div>
                </form>
        </div>
        <script>
            const dateRegex = /[0-9]{2}\/[0-9]{2}\/[0-9]{2} [0-1][0-9]:[0-5][0-9]:[0-5][0-9] (AM|PM)/;
            const titleInput = document.getElementById('title-input');
            const dateInput = document.getElementById('date-input');
            const descInput = document.getElementById('description-input');
            const footer = document.getElementById('footer');
            function addNote() {
                if (!titleInput.value || titleInput.value.length > 20) {
                    alert('Title needs to be 1 to 20 characters long');
                }
                if (!dateInput.value || dateRegex.test(dateInput)) {
                    alert('Date needs to be exactly in this format 00/00/00 00:00:00 AM/PM');
                }
                if (!descInput.value || descInput.value.length > 1000) {
                    alert('Title needs to be 1 to 20 characters long');
                }
                footer.submit();
            }
        </script>
        <script src="todo.js"></script>
    </body>
</html>