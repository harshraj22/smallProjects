<?php
    session_start();
    require_once 'login.php';
    echo "Hallo</br>";
    if(!isset($_SESSION['delete_author']) || !$_SESSION['delete_title'] || !$_SESSION['delete_content'] || !$_SESSION['delete_date'])
        die("Could not delete </br>");
    // $conn = mysqli_connect()    
    $connection = mysqli_connect($db_hostname,$db_user,$db_password,$db_database);
    $query = "DELETE FROM {$db_table_posts} WHERE author='{$_SESSION['delete_author']}' AND title='{$_SESSION['delete_title']}' AND day='{$_SESSION['delete_date']}' ";

    $result = mysqli_query($connection,$query);
    if(!$result)
        die("Error while deleting </br>".mysqli_error($connection));
    else    
        echo "Successfully Deleted</br>";

?>