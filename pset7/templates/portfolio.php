<?php
    require("navbar.php");
?>

<div>
    <p>Hello, <?= htmlspecialchars($user["username"]) ?> </p>
    <p>Here are you current holdings: </p>
</div>


<div>
    <table>
    <?php foreach ($positions as $position): ?>

    <tr>
        <td>Ticker: <?= $position["symbol"] ?></td>
        <td>Stock Name: <?= $position["name"] ?></td>
        <td>Shares Owned: <?= $position["shares"] ?></td>
        <td>Current Price Per Share: <?= $position["price"]  ?></td>
        <td>Current Value: <?= $position["value"]   ?></td>
    </tr>

<?php endforeach ?>
</table>
</div>
<div>
    <p>You currently have <?= htmlspecialchars($user["cash"]) ?> in your account. </p>
</div>
<div>
    <a href="change_password.php">Change Your Password</a>
</div>

<?php
    require("logout_button.php");
?>
