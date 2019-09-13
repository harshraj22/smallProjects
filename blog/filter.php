<?php
    require_once 'login.php';
    $connection = mysqli_connect($db_hostname,$db_user,$db_password,$db_database);

    if(!$connection){
        die('Couldnt connect to database. <br/>'.mysqli_connect_error($connection));
    }

    $result = 0;

    // echo "data are : ".$_POST['author_name']." ".$_POST['post_date']."<br/>";
    // echo (empty($_POST['author_name'])==true)." -= ".(empty($_POST['post_date'])==true)."<br/>";

    if(empty($_POST['author_name'])==true && empty($_POST['post_date'])==true){
        die("Empty data. <br/>");
    }
    else if(empty($_POST['post_date'])==true){
        $query = "SELECT * FROM ".$db_table_posts." WHERE author = '".$_POST['author_name']."'";
        $result = mysqli_query($connection,$query);
        // echo $query."<br>";
    }
    else if(empty($_POST['author_name'])==true){
        $query = "SELECT * FROM ".$db_table_posts." WHERE day = '".$_POST['post_date']."'";
        $result = mysqli_query($connection,$query);
        // if($result)
        //     echo "Searched <br/>";
        // else
        //     echo "was inside <br/>";
    }
    else {
        $query = "SELECT * FROM ".$db_table_posts."WHERE day = '".$_POST['post_date']."' AND author = '".$_POST['author_name']."'";
        $result = mysqli_query($connection,$query);
    }

    if(!$result){
        die('Error while searching.'.mysqli_error($connection));
    }

    $numRows = mysqli_num_rows($result);

    for($i=0;$i<$numRows;$i++){
        $rows = mysqli_fetch_row($result);

        // print_r($rows)."<br/>";

        $author = $rows[0];
        $title = $rows[1];
        $content = $rows[2];
        $date = $rows[3];

        echo <<< _END
            <div>
                <h1> $title </h1>
                <h5> By : $author</h5>
                <hr>
                <h3> $content </h3>
                <h6> Dated : $date <br/></h6>
            </div>
        _END;
    }

?>