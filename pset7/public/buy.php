<?php
    
    // configuration
    require("../includes/config.php");
    
     //If user reached page via page via link or clicks
    if ($_SERVER["REQUEST_METHOD"] == "GET")
    {
        // else render form
        render("quote_form.php", ["title" => "Get Quote"]);
    }

    // else if user reached page via POST (as by submitting a form via POST)
    else if ($_SERVER["REQUEST_METHOD"] == "POST")
    {
        
        $_POST["symbol"] = strtoupper($_POST["symbol"]);
        
        //validate submission
        if (empty($_POST["symbol"]) || empty($_POST["price"]))
        {
            apologize("Something went wrong. Please try your selection again..");
        }
        //make sure the number of shares being bought is a positive whole number
        else if (empty($_POST["numshares"]) || $_POST["numshares"] < 1)
        {
            apologize("You must provide a number of shares to buy. It must be a whole number.");
        
        }
        
        //make sure numshares is an int
        $numshares = (int) $_POST["numshares"];
        
        //final sanity check
        if (preg_match("/^\d+$/", $numshares) != true)
         {
            apologize("You must provide a number of shares to buy. It must be a whole number.");
        
        }
        
        //recall user data to grab available cash
        $rows = query("SELECT * FROM users WHERE id = ?", $_SESSION["id"]);
        $row = $rows[0];
        
        //format avialable cash and price of shares
        $numshares = (int) $_POST["numshares"];
        $price = number_format($_POST["price"], 4, '.', ',');
        $buying = number_format($numshares, 4, '.', ',') * $price;
        $buying = number_format($buying, 4, '.', ',');
        $buying = (double) $buying;
        $cash = $row["cash"];
        

        //verify that the user is not trying to buy more shares than they can afford
        if($buying > $cash) 
        {
            apologize("You do not have enough money to buy those shares.");
        }
       
        //else add shares to user's table and subtract the price from their cash
        else
        {
        
        $query = query("INSERT INTO holdings (id, symbol, shares) VALUES(?, ?, ?) 
                        ON DUPLICATE KEY UPDATE shares = shares + VALUES(shares)",
                        $_SESSION["id"], $_POST["symbol"], $numshares);
                        
        $updatecash = query("UPDATE users SET cash = cash - ? WHERE id = ?", $buying, $_SESSION["id"]);
        
        $history = query("INSERT INTO history (id, action, symbol, name, shares, price ) VALUES(?, 'Bought', ?, ?,?, ?)",
                        $_SESSION["id"], $_POST["symbol"], $_POST["name"], $numshares, $price ); 
        
        }
        
    
    // render congratulations page
    render("bought.php", ["title" => "Congratulations", "stock" => $_POST["symbol"], "shares" => $_POST["numshares"], 
             "cost" => $buying ]);
    
    }
    
?>
