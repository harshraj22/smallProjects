<?php
    require_once 'login.php';
    if(!isset($_POST['pass'])){
        echo "<script type='text/javascript'>alert('Enter Password !'); history.go(-2);</script>";        
    }
    else if($_POST['pass'] == $admin_password){
        echo "Welcome Admin.";
        header("Location: http://localhost:8080/blog/post.html");
        exit;
    }
    else {
        echo "<script type='text/javascript'>alert('Wrong password !'); history.go(-2);</script>";
        // header("Location: javascript:history.back(-2)");
        // exit;
    }

?>