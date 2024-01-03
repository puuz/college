<?php
#Sam Farris
#CS248_001
#dynamic rotten tomato movie reviews

$movie_name=$_REQUEST["film"];
list($title, $year)=file("$movie_name/info.txt");
$review_files=glob("$movie_name/review*.txt");
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
            <td><img src="<?=$movie_name?>/overview.png" alt="general overview"></td>
            <td colspan="2">
            <dl>
                <?php
                #reads the overview file for specificed movie name and
                #dynamically displays title and description from overview
                foreach (file("$movie_name/overview.txt") as $info_line) {
                    list($term, $defn)=explode(":", $info_line);
                ?>
                    <dt><?=$term?></dt>
                    <dd><?=$defn?></dd>
                <?php
                }
                ?>
            </dl>
            </td>
        </tr>
        <tr>
            <td colspan="3" class="heading">Reviews</td>
        </tr>
        <?php
        #loops over each review file from review_files as it's an "array" and
        #dynamically displays the review author and review itself
        foreach($review_files as $reviewfile) {
            list($review, $rating, $critic, $publication)=file($reviewfile);
            $tomatoimage=strtolower(trim($rating));
        ?>
            <tr class="review">
                <th><?=$critic?><br><?=$publication?></th>
                <td><img src="<?=$tomatoimage?>.gif" alt="<?=$tomatoimage?>"></td>
                <td><?=$review?></td>
            </tr>
        <?php
        }
        ?>
    </table>
</body>
</html>