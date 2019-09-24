<?php
// add next and prev button, display only 5 posts per page (don't hardcode)
    session_start();
    require_once 'login.php';
    $connection = mysqli_connect($db_hostname,$db_user,$db_password,$db_database);

    echo <<< _END
        <!-- Do not hard-code link , adjust for case when page is more than 1 (we don't need to go back just 2 pages) -->
        <button onclick="window.history.go(-2)">Prev</button>
    _END;

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
        $query = "SELECT * FROM {$db_table_posts} WHERE day = '{$_POST['post_date']}'";
        $result = mysqli_query($connection,$query);
        // if($result)
        //     echo "Searched <br/>";
        // else
        //     echo "was inside <br/>";
    }
    else {
        $query = "SELECT * FROM {$db_table_posts} WHERE day = '{$_POST['post_date']}' AND author = '{$_POST['author_name']}'";
        $result = mysqli_query($connection,$query);
    }

    if(!$result){
        die('Error while searching.'.mysqli_error($connection));
    }

    $numRows = mysqli_num_rows($result);

    for($i=0;$i<$numRows;$i++){
        $rows = mysqli_fetch_row($result);

        // print_r($rows)."<br/>";
        $pic = '';
        if(isset($rows[5]))
            $pic = $rows[5];

        $author = $rows[0];
        $title = $rows[1];
        $content = $rows[2];
        $date = $rows[3];

        echo <<< _END
            <div>
                <h1> $title </h1>
                <img src="./pics/$pic" height='420' width='420'>
                <h5> By : $author</h5>
                <hr>
                <h3> $content </h3>
                <h6> Dated : $date <br/></h6>
            </div>
        _END;
    }

    if($numRows == 0){
        echo "No data matched for this input <br/>";
    }

?>