<?php
    require("navbar.php");
?>

<div id="sold">

  <p> Congratulations you've sold shares of <?= htmlspecialchars($name) ?>!</p>
  <p> <?= htmlspecialchars($refund) ?> has been credited to your account. </p>
 </div>
<div>
    <p><a href="index.php">Back to portfolio</a></p>
</div>

<?php
    require("logout_button.php");
?>
