<?php
    require("navbar.php");
?>

<div id="bought">

  <p> Congratulations you now own <?= htmlspecialchars($shares) ?> of <?= htmlspecialchars($stock) ?>!</p>
  <p> <?= htmlspecialchars($cost) ?> has been debited from your account. </p>
 </div>
<div>
    <p><a href="index.php">Back to portfolio</a></p>
    <p> or <a hrem="quote.php">Buy more</a></p>
</div>
    
<?php
    require("logout_button.php");
?>
