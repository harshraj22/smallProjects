<?php
    require_once 'login.php';
    $connection = mysqli_connect($db_hostname,$db_user,$db_password,$db_database);

    echo <<< _END
        <!-- Do not hard-code link (the number of pages to go back) -->
        <button onclick="window.history.go(-3)">Prev</button>
    _END;

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
        echo "Error saving the data.".mysqli_error($connection)."<br/>";
    else
        echo "Data successfully saved. <br/>";
    
    // $id = mysqli_query($connection,"SELECT LAST_INSERT_ID()");

    $id_query = "SELECT id FROM ". $db_table_posts."  ORDER BY id DESC LIMIT 1";
    $id = mysqli_query($connection,$id_query);

    if(!$id){
        echo "query failed <br/>";
        echo $id_query.mysqli_error($connection)."<br/>";
        die('');
    }
    else{
        echo "passed with primary key : ";
        $res = mysqli_fetch_array($id);
        echo $res[0]."<hr>";
    }

    echo "Author : ".$_POST['author']."<br/>";
    echo "Title : ".$_POST['title']."<br/>";
    echo "Contents : ".$_POST['contents']."<br/>";
    echo "Dated : ".$_POST['date']."<br/>";
?>