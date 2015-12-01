<?php

     // configuration
    require("../includes/config.php");
    
    //Recall all data for the user and their current holdings. 
    $rows = query("SELECT * FROM history WHERE id = ?", $_SESSION["id"]);
    $user = query("SELECT username FROM users WHERE id = ?", $_SESSION["id"]);
    
     //store data to be used later
    $positions = [];
    
    if ($rows != false)
   
    {
        
        foreach ($rows as $row)
        {
            $positions[] = [
            "action" => $row["action"],
            "symbol" => $row["symbol"],
            "name" => $row["name"],
            "price" => number_format($row["price"], 4, '.', ','),
            "shares" => $row["shares"],
            "symbol" => $row["symbol"],
            "value" => number_format(($row["price"] * $row["shares"]), 4, '.', ','),
            "timestamp" => $row["timestamp"]
            ];
        }
    }
    
    // render history
    render("history_log.php", ["positions" => $positions,  "user" => $user[0]["username"], "title" => "History"]);

    
?>
