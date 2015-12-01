<?php

     //configuration
     require("../includes/config.php"); 
     
     
     // if user reached page via GET (as by clicking a link or via redirect)
    if ($_SERVER["REQUEST_METHOD"] == "GET")
    {
    
     //render page
     render("quote_form.php", ["title" => "Get Quote"]);
    }
    
 
    else if ($_SERVER["REQUEST_METHOD"] == "POST")
    {
        $_POST["symbol"] = strtoupper($_POST["symbol"]);
        
        //look up stocks
        $stock = lookup($_POST["symbol"]);
        
        //stock not found, apologize
        if($stock === false)
        {
            apologize("Symbol not found. Please check that it is spelled correctly");
        }
        
        //number format the price of the stock
        $format_price = number_format($stock["price"], 4, '.', ',');

        //render the quote in stock_price.
        render("stock_price.php", ["symbol" => $_POST["symbol"], "name" => $stock["name"], "price" => $format_price]);
    }


?>
