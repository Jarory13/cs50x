<?php
    require("navbar.php");
?>
<div id="quote">

  <p> Stock Symbol: <?= htmlspecialchars($symbol) ?> </p>
  <p> Company Name: <?= htmlspecialchars($name) ?> </p>
  <p> Current Price: <?= htmlspecialchars($price) ?> </p>
 </div>

<form action="buy.php" method="post">
    <fieldset>
    <div class="form-group">
            <input class="form-control" name="numshares" placeholder="Number of Shares" type="number" min="1"/>
    </div>
    <div>
         <input type="hidden" name="symbol" value="<?php echo $symbol;?>">
         <input type="hidden" name="price" value="<?php echo $price;?>">
         <input type="hidden" name="name" value="<?php echo $name;?>"> 
         
    </div>
         <div class="form-group">
            <button type="submit" class="btn btn-default">Buy Now!</button>
        </div>
    </fieldset>
    
<?php
    require("logout_button.php");
?>

