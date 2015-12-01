<?php

    // configuration
    require("../includes/config.php");
    
    //Recall all data for the user and their current holdings. 
    $rows = query("SELECT * FROM holdings WHERE id = ?", $_SESSION["id"]);
    
    //store data to be used later
    $positions = [];
    
    foreach ($rows as $row)
    {
        $stock = lookup($row["symbol"]);
        if ($stock !== false)
        {
            $positions[] = [
            "name" => $stock["name"],
            "price" => number_format($stock["price"], 4, '.', ','),
            "shares" => $row["shares"],
            "symbol" => $row["symbol"],
            "value" => number_format(($stock["price"] * $row["shares"]), 4, '.', ',')
            ];
        }
    }
    
    //If user reached page via page via link or clicks
    if ($_SERVER["REQUEST_METHOD"] == "GET")
    {
        // else render form
        render("continue_sell.php", ["title" => "Sell", "positions" => $positions]);
    }

    // else if user reached page via POST (as by submitting a form via POST)
    else if ($_SERVER["REQUEST_METHOD"] == "POST")
    {
        //validate submission
        if (empty($_POST["symbol"]))
        {
            apologize("You must provide a stock to sell.");
        }
        else if (empty($_POST["amount"]) || $_POST["amount"] < 1 || preg_match("/^\d+$/", $_POST["amount"]) != true)
        {
            apologize("You must provide number of shares to sell. Shares must be whole numbers and you must sell at least one share.");
        
        }
        //check to see if stock exist and update the holdings
        $update = query("SELECT * FROM holdings WHERE id = ? AND symbol = ?", $_SESSION["id"], $_POST["symbol"]);
        $_POST["symbol"] = strtoupper($_POST["symbol"]);
        
        
        //stock not found
        if(count($update) != 1)
        {
            apologize("Stock not found");
        }
        else
        {
            $update = $update[0];    
        }
        
        //verify that the user is not trying to sell more shares than they own
        if($_POST["amount"] > $update["shares"])
        {
            apologize("You cannot sell more shares than you own.");
        }
        else
        {
            query("UPDATE holdings SET shares = shares - ? WHERE id = ? AND symbol = ?", 
            $_POST["amount"], $_SESSION["id"], $_POST["symbol"]);
            $removeshares = query("SELECT * FROM holdings WHERE id = ? AND symbol = ?", $_SESSION["id"], $_POST["symbol"]);
            $removeshares = $removeshares[0];
        }
        
        if($removeshares["shares"] < 1)
        {
            query("DELETE FROM holdings WHERE id = ? AND symbol = ?", $_SESSION["id"], $_POST["symbol"]);
        }
        
        //finally, update the cash in users account
        $grabvalue = lookup($_POST["symbol"]);
        
        $adjustedvalue = number_format($grabvalue['price'], 4, '.', ',');
        $cashrefund = $_POST["amount"] * $adjustedvalue;
        query("UPDATE users SET cash = cash + ? WHERE id = ?", $cashrefund, $_SESSION["id"]);
        
        //add to history
        $history = query("INSERT INTO history (id, action, symbol, name, shares, price ) VALUES(?, 'Sold', ?, ?, ?, ?)",
                        $_SESSION["id"], $_POST["symbol"], $grabvalue["name"], $_POST["amount"], $adjustedvalue);
           
           
    // render verification page
    render("sold.php", ["title" => "Sold", "name" => $grabvalue["name"], "refund" => $cashrefund]);
    }
?>
