<?php
    require("navbar.php");
?>

<div>
  <p>Please choose a stock to sell. Enter the stock Ticker and number of shares you wish to sell in the form below. </p>
  <p> You currently have holdings in: </p>   
</div>
<div>
    <center>
    <table>
        <?php foreach ($positions as $position): ?>
            <tr>
                <td>Ticker: <?= $position["symbol"] ?></td>
                <td>Stock Name: <?= $position["name"] ?></td>
                <td>Shares <?= $position['shares'] ?> </td>
            </tr>
        <?php endforeach ?>
    </table>
    </center>
</div>
<form action="sell.php" method="post">
         <fieldset>
        <div class="form-group">
            <input autofocus class="form-control" name="symbol" placeholder="Ticker" type="text"/>
        </div>
        <div class="form-group">
            <input class="form-control" name="amount" placeholder="Number of Shares" type="number" min="1"/>
            
        </div>
        <div class="form-group">
            <button type="submit" class="btn btn-default">Continue?</button>
        </div>
    </fieldset>
</form>

<?php
    require("logout_button.php");
?>
