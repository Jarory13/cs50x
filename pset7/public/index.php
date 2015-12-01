<?php

    // configuration
    require("../includes/config.php"); 
    
    
    $currentuser = query("SELECT * FROM users WHERE id = ?", $_SESSION["id"]);
    $rows = query("SELECT * FROM holdings WHERE id = ?", $_SESSION["id"]);
    
    $currentuser = $currentuser[0];
   
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

    // render portfolio
    render("portfolio.php", ["positions" => $positions,  "user" => $currentuser, "title" => "Portfolio"]);

?>
