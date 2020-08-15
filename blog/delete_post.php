<?php
    session_start();
    require_once 'login.php';
    // echo "Hallo</br>";

    if(!isset($_SESSION['loggedIn']) || $_SESSION['loggedIn']==false){
        header("Location: validate.html");
        exit;
    }

    if(!isset($_POST['delete_author']) || !isset($_POST['delete_title']) || !isset($_POST['delete_content']) || !isset($_POST['delete_date']))
        die("Could not delete </br>");
    // $conn = mysqli_connect()    
    $connection = mysqli_connect($db_hostname,$db_user,$db_password,$db_database);
    $query = "DELETE FROM {$db_table_posts} WHERE author='{$_POST['delete_author']}' AND title='{$_POST['delete_title']}' AND day='{$_POST['delete_date']}' ";

    echo $query."</br></br>";
    echo $_POST['delete_author']."<br/>";

    $result = mysqli_query($connection,$query);
    if(!$result)
        die("Error while deleting </br>".mysqli_error($connection));
    else    
        echo "Successfully Deleted</br>";

?>