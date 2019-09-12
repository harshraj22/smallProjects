<?php
    require_once 'login.php';
    $connection = mysqli_connect($db_hostname,$db_user,$db_password,$db_database);

    if(!$connection)
        die('Error while posting.'.mysqli_connect_error());
    echo "Successfuly entered the database. <br/>";

    $author = $_POST['author'];
    $title = $_POST['title'];
    $contents = $_POST['contents'];
    $date = $_POST['date'];

    $query = "INSERT INTO ".$db_table_posts."(author,title,content,day) VALUES ('" . $author . "','" . $title . "','" . $contents . "','" . $date . "')";

    $result = mysqli_query($connection,$query);

    if(!$result)
        echo "Error saving the data.<br/>";
    else
        echo "Data successfully saved. <br/>";

    echo $_POST['author']."<br/>";
    echo $_POST['title']."<br/>";
    echo $_POST['contents']."<br/>";
    echo $_POST['date']."<br/>";
?>