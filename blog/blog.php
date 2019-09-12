<?php
    require_once 'login.php';
    $connection = mysqli_connect($db_hostname,$db_user,$db_password,$db_database);

    if(!$connection){
        die('<br/>Connection failed<br/>'.mysqli_connect_error());
    }
    echo "Connection successful. <br/>";

    $query = mysqli_query($connection,"SELECT * FROM " . $db_table_posts);

    if(!$query)
        die('Some error occured while fetching data.'.mysqli_error());
    $num_of_rows = mysqli_num_rows($query);

    // echo "Number of rows found : ".$num_of_rows."with query "."<br/>";

    for($i=0;$i < ($num_of_rows);$i++){
        $rows = mysqli_fetch_row($query);
        // for($j=0;$j < count($rows);$j++){
        //     echo $rows[$j] . "<br/>";
        // }
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


    mysqli_close($connection);
?>