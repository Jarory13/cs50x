<?php
    require("navbar.php");
?>

<div>
    <p>Hello, <?= htmlspecialchars($user) ?> </p>
    <p>Here your portfolio history. </p>
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
        <td> <?= $position["action"]?> </td>
        <td>Timestamp: <?= $position["timestamp"] ?></td>
    </tr>
    <?php endforeach ?>
    </table>
</div>
<?php
    require("logout_button.php");
?>
