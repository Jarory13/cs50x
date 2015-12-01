<?php

    // configuration
    require("../includes/config.php");

    // if user reached page via GET (as by clicking a link or via redirect)
    if ($_SERVER["REQUEST_METHOD"] == "GET")
    {
        // else render form
        render("changePass_form.php", ["title" => "Change Password"]);
    }
    
    else if ($_SERVER["REQUEST_METHOD"] == "POST")
    {
        // validate submission

        if (empty($_POST["email"]))
        {
            apologize("For your security, please provide the email listed with this account.");
        }
        else if (empty($_POST["password"]))
        {
            apologize("You must provide a new password.");
        }
      
        else if (empty($_POST["confirmation"]) || $_POST["password"] !== $_POST["confirmation"])
        {
            apologize("Passwords do not match. Please re-enter passwords");
        }
        
         $rows = query("SELECT * FROM users WHERE email =?", $_POST["email"]);
         
        if (count($rows) != 1)
        {
            apologize("Email not found. Please re-enter your email address");
        }
        
        else
        {
        $update = query("UPDATE users SET hash = ? WHERE id = ?", crypt($_POST["password"]), $_SESSION["id"]);
        }
        
        render("password_changed.php", ["title" => "Password Changed"]);
    }
    
    
?>
