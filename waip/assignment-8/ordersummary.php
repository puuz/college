<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="utf-8">
    <title>Order Summary</title>
    <link href="ordersummary.css" rel="stylesheet" type="text/css">
</head>
<body background="metal.jpg">
    <?php
        # check if request has the required post data
        if ($_POST["items"] && $_POST["firstname"] && $_POST["lastname"] && $_POST["street"] && $_POST["city"] && $_POST["state"] && $_POST["zip"]) {
            # store post data in local variables
            $items = $_POST["items"];
            $firstname = $_POST["firstname"];
            $lastname = $_POST["lastname"];
            $street = $_POST["street"];
            $city = $_POST["city"];
            $state = $_POST["state"];
            $zip = $_POST["zip"];
            $total = 0;
            $shipping = 0;
            ?>
            <h1>Order Summary</h1>
            <p>Thank you <?=$firstname?> for your order to:</p>
            <p><?=$street?></p>
            <p><?=$city?>, <?=$state?> <?=$zip?></p>

            <p>You ordered the following items:</p>
            <table class="items">
                <tr class="heading">
                    <th>Item</th>
                    <th>Price</th>
                </tr>
                <?php
                # loops over items array and takes the item and price in each element
                # to be displayed what items were purchased
                foreach($items as $item => $price) {
                    ?>
                    <tr>
                        <td><?=$item?></td>
                        <td><?=$price?></td>
                    </tr>
                    <?php
                    $total += $price;
                }
                # calculates the shipping cost by current total of what was bought
                if ($total < 500) {
                    $shipping = 25;
                } else if ($total < 1000) {
                    $shipping = 50;
                } else {
                    $shipping = 100;
                }
                $total += $shipping;
                ?>
                <tr>
                    <td>Shipping</td>
                    <td><?=$shipping?></td>
                </tr>
                <tr>
                    <td>Total</td>
                    <td><?=$total?></td>
                </tr>
            </table>
            <?php
        # otherwise give a 404 page
        } else {
            ?>
            <div class="goback">
                <a href="forsale.html">Go back and complete the form properly</a>
            </div>
            <?php
        }
        ?>
</body>
</html>