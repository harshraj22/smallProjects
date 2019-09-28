<?php
    session_start();

    if(isset($_SESSION['loggedIn']) && $_SESSION['loggedIn'] == true){
        echo <<< _END
            <button type="submit" onclick="window.location.href='http://localhost:8080/blog/logout.php'">Logout</button>
        _END;
    }
    else{
        echo <<< _END
            <button type="submit" onclick="window.location.href='http://localhost:8080/blog/validate.html'" >Login</button>
        _END;
    }

    require_once 'login.php';
    $numOfPostPerPage = 5;

    if(isset($_SESSION['loggedIn']) && $_SESSION['loggedIn'] == true){
        echo <<< _END
            <!-- remove hardcoded links -->
            <button type="submit" onclick="window.location.href= 'http://localhost:8080/blog/validate.php'";>Post</button>
            <button type="submit" onclick="window.location.href= 'http://localhost:8080/blog/filter.html'";>Filter</button>
        _END;
    }
    else {
        echo <<< _END
            <!-- remove hardcoded links -->
            <button type="submit" onclick="window.location.href= 'http://localhost:8080/blog/validate.html'";>Post</button>
            <button type="submit" onclick="window.location.href= 'http://localhost:8080/blog/filter.html'";>Filter</button>

        _END;
    }
    $connection = mysqli_connect($db_hostname,$db_user,$db_password,$db_database);

    if(!$connection){
        die('<br/>Connection failed<br/>'.mysqli_connect_error());
    }
    // echo "Connection successful. <br/>";

    $start = $_GET['page']*$numOfPostPerPage;
    $end = $start + $numOfPostPerPage;

    $query = mysqli_query($connection,"SELECT * FROM " . $db_table_posts . " ORDER BY id LIMIT {$start},1234567" );

    // print_r($_GET)."<br/>";

    // echo "Start and end are : ".$start." = ".$end." = ".$_GET['page']." / ".isset($_GET['page'])."<br/>";

    if(!$query)
        die('Some error occured while fetching data.'.mysqli_error($connection));
    $num_of_rows = mysqli_num_rows($query);

    // echo "Number of rows found : ".$num_of_rows." with query "."<br/>";

    for($i=0;$i < min($num_of_rows,$numOfPostPerPage);$i++){
        $rows = mysqli_fetch_row($query);

        $author = $rows[0];
        $title = $rows[1];
        $content = $rows[2];
        $date = $rows[3];
        $pic = '';
        if(isset($rows[5]))
            $pic = $rows[5];

        $_SESSION["delete_author"] = $author;
        $_SESSION['delete_title'] = $title;
        $_SESSION['delete_content'] = $content;
        $_SESSION['delete_date'] = $date;

        echo <<< _END
            <div>
                <h1> <h4> $i. </h4> $title </h1>
                <img src="./pics/$pic" height='420' width='420'>
                <h5> By : $author</h5>
                <hr>
                <h3> $content </h3>
                <h6> Dated : $date <br/></h6>
                             
                <form action='delete_post.php' method='post'>
                    <input type='submit' value="Delete">
                </form>
            </div>
        _END;
    }

    $nxt = $_GET['page'] + 1;

    if($num_of_rows > $numOfPostPerPage){
        echo <<< _END
            <form action="blog.php" method="GET">
                <button type="submit" name='page' value=$nxt>Next</button>
            </form>
        _END;
    }

    $prev = $_GET['page'] - 1;

    if($_GET['page'] != 0){
        echo <<< _END
            <button onclick="window.history.back()">Prev</button>
        _END;
    }

    mysqli_close($connection);
?>