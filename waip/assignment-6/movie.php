<?php
#Sam Farris
#CS248_001
#dynamic mysql database rotten tomato movie reviews

$movie_name = $_REQUEST["film"];

$servername = "sql9.freemysqlhosting.net";
$database = "sql9261490";
$username = "sql9261490";
$password = "XVE35hbJ2t";

# establishes connection with mysql database
$conn = mysqli_connect($servername, $username, $password, $database);
if (!$conn) {
    die ("Connection Failed: " . mysqli_connect_error());
}

# selects movie information from film's value used in website query and format results
$sql = "SELECT id, title, rel, director, producer, rating, img, synopsis FROM movie WHERE film = '$movie_name'";
$result = mysqli_query($conn, $sql);
$row = mysqli_fetch_assoc($result);

# store row results in seperate variables
$movieid = $row["id"];
$title = $row["title"];
$releasedate = $row["rel"];
$director = $row["director"];
$producer = $row["producer"];
$rating = $row["rating"];
$image = $row["img"];
$synopsis = $row["synopsis"];

$year = explode("-", $releasedate)[0];
$actors = array();

# select name of actors for queried movie
$sql = "SELECT name FROM actor a JOIN casting c on a.ID = c.actorid WHERE c.movieid = '$movieid'";
$results = mysqli_query($conn, $sql);

# format join query of actors into array
while($row = mysqli_fetch_assoc($results)) {
    array_push($actors, $row["name"]);
}

$reviews = array();

# select reviews information for queried movie
$sql = "SELECT rating, critic, publication, review FROM reviews WHERE movieid = '$movieid'";
$results = mysqli_query($conn, $sql);

# format regular query of reviews into array
while($row = mysqli_fetch_assoc($results)) {
    array_push($reviews, $row);
}

# close mysql connection
mysqli_close($conn);
?>
<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="utf-8">
    <title><?=$title?> - Rancid Tomatoes</title>
    <link href="movie.css" rel="stylesheet" type="text/css">
</head>
<body background="background.png">
    <span><img src ="banner.png" alt="Rancid Tomatoes"></span>
    <table>
        <tr>
            <td colspan="3" class="heading"><?=$title?> (<?=$year?>)</td>
        </tr>
        <tr>
            <!-- had to use https otherwise there was a security error for showing the image -->
            <td><img src="https://mscs-php.uwstout.edu<?=$image?>" alt="general overview"></td>
            <td colspan="2">
            <dl>
                <dt>Starring</dt>
                <?php
                #loops over each actor from the actors array and
                #dynamically displays the actor's name
                foreach($actors as $actor) {
                    ?>
                    <dd><?=$actor?></dd>
                    <?php
                }
                ?>
                <dt>Director</dt>
                <dd><?=$director?></dd>

                <dt>Producer</dt>
                <dd><?=$producer?></dd>

                <dt>Rating</dt>
                <dd><?=$rating?></dd>

                <dt>Release Date</dt>
                <dd><?=$releasedate?></dd>

                <dt>Synopsis</dt>
                <dd><?=$synopsis?></dd>
            </dl>
            </td>
        </tr>
        <tr>
            <td colspan="3" class="heading">Reviews</td>
        </tr>
        <?php
        #loops over each review from the reviews array and
        #dynamically displays the review critic and review itself
        foreach($reviews as $review) {
            $tomatoimage=strtolower(trim($review["rating"]));
        ?>
            <tr class="review">
                <th><?=$review["critic"]?><br><?=$review["publication"]?></th>
                <td><img src="<?=$tomatoimage?>.gif" alt="<?=$tomatoimage?>"></td>
                <td><?=$review["review"]?></td>
            </tr>
        <?php
        }
        ?>
    </table>
</body>
</html>