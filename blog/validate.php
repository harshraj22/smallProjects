<?php
    session_start();
    require_once 'login.php';
    if(isset($_SESSION['loggedIn']) && $_SESSION['loggedIn'] == true){
        echo "Welcome Admin.";
        $_SESSION['loggedIn'] = true;
        header("Location:  post.html");
        exit;        
    }
    else if(!isset($_POST['pass'])){
        echo "<script type='text/javascript'>alert('Enter Password !'); history.go(-2);</script>";        
    }
    else if($_POST['pass'] == $admin_password){
        echo "Welcome Admin.";
        $_SESSION['loggedIn'] = true;
        header("Location:post.html");
        exit;
    }
    else {
        echo "<script type='text/javascript'>alert('Wrong password !'); history.go(-2);</script>";
        // header("Location: javascript:history.back(-2)");
        // exit;
    }

?>