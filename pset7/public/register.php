<?php

    // configuration
    require("../includes/config.php");

    // if user reached page via GET (as by clicking a link or via redirect)
    if ($_SERVER["REQUEST_METHOD"] == "GET")
    {
        // else render form
        render("register_form.php", ["title" => "Register"]);
    }

    // else if user reached page via POST (as by submitting a form via POST)
    else if ($_SERVER["REQUEST_METHOD"] == "POST")
    {
         // validate submission
        if (empty($_POST["username"]))
        {
            apologize("You must provide your username.");
        }
        else if (empty($_POST["password"]))
        {
            apologize("You must provide your password.");
        }
        else if (empty($_POST["email"]))
        {
            apologize("You must provide an email.");
        }
        else if (empty($_POST["confirmation"]) || $_POST["password"] !== $_POST["confirmation"])
        {
            apologize("Passwords do not match. Please re-enter passwords");
        }
        
        //check that Username doesn't exist
       
        $rows = query("SELECT * FROM users WHERE username = ? OR email =?", $_POST["username"], $_POST["email"]);

        // if we found user, prompt for new name
        if (count($rows) == 1)
        {
            apologize("Account already exists.");
        }
        else
        {
        query("INSERT INTO users (username, email, hash, cash) VALUES(?, ?, ?, 1000.00)", 
        $_POST["username"], ($_POST["email"]), crypt($_POST["password"]));
        }
        
        //get the user's id
        $rows = query("SELECT LAST_INSERT_ID() AS id");
        $id = $rows[0]["id"];
        
        // remember that user's now logged in by storing user's ID in session
        $_SESSION["id"] = $id;
        
        
         // redirect to index
         redirect("/index.php");
        
    }

?>
