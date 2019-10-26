<?php
    session_start();
?>

<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=fit-content, initial-scale=1.0">
    <meta http-equiv="X-UA-Compatible" content="ie=edge">
    <link rel="stylesheet" href="https://stackpath.bootstrapcdn.com/bootstrap/4.3.1/css/bootstrap.min.css" integrity="sha384-ggOyR0iXCbMQv3Xipma34MD+dH/1fQ784/j6cY/iJTQUOhcWr7x9JvoRxT2MZw1T" crossorigin="anonymous">
    <link rel="stylesheet" href="https://use.fontawesome.com/releases/v5.7.0/css/all.css" integrity="sha384-lZN37f5QGtY3VHgisS14W3ExzMWZxybE1SJSEsQp9S+oqd12jhcu+A56Ebc1zFSJ" crossorigin="anonymous">

</head>
<body>

        <nav class="navbar navbar-expand-lg navbar-light bg-light mb-4">
            <a class="navbar-brand" href="index.php">Home</a>
            <button class="navbar-toggler" type="button" data-toggle="collapse" data-target="#navbarSupportedContent" aria-controls="navbarSupportedContent" aria-expanded="false" aria-label="Toggle navigation">
                <span class="navbar-toggler-icon"></span>
            </button>

            <div class="collapse navbar-collapse" id="navbarSupportedContent">
                <ul class="navbar-nav mr-auto">
                    <li class="nav-item active">
                        <a class="nav-link" href="blog.php?page=0">Blog <span class="sr-only">(current)</span></a>
                    </li>
                    <li class="nav-item">
                        <?php
                            if(isset($_SESSION['loggedIn']) && $_SESSION['loggedIn'] == true){
                                echo <<< _END
                                    <a class="nav-link" href="logout.php">Logout</a>
                                _END;
                            }
                            else{
                                echo <<< _END
                                    <a class="nav-link" href="validate.html">Login</a>
                                _END;
                            }
                        ?>
                        <!-- <a class="nav-link" href="validate.html">Login</a> -->
                    </li>
                    <li class="nav-item">
                        <?php
                            if(isset($_SESSION['loggedIn']) && $_SESSION['loggedIn'] == true){
                                echo <<< _END
                                    <a class="nav-link" href="validate.php">Post</a>
                                _END;
                            }
                            else{
                                echo <<< _END
                                    <a class="nav-link" href="validate.html">Post</a>
                                _END;
                            }
                        ?>
                    </li>
                    <li class="nav-item dropdown">
                        <a class="nav-link dropdown-toggle" href="#" id="navbarDropdown" role="button" data-toggle="dropdown" aria-haspopup="true" aria-expanded="false">
                          Dropdown
                        </a>
                        <div class="dropdown-menu" aria-labelledby="navbarDropdown">
                            <a class="dropdown-item" href="#">Action</a>
                            <a class="dropdown-item" href="#">Another action</a>
                            <div class="dropdown-divider"></div>
                                <a class="dropdown-item" href="#">Something else here</a>
                            </div>
                    </li>
                </ul>
                <form class="form-inline my-2 my-lg-0">
                    <button class="btn btn-outline-success my-2 my-sm-0" type="submit" onclick="window.location.href='filter.html'">Filter</button>
                </form>
            </div>
        </nav>


        <div class="container jumbotron ">
            <?php
            // session_start();

                if(isset($_SESSION['loggedIn']) && $_SESSION['loggedIn'] == true){
                    echo <<< _END
                        <button type="submit" onclick="window.location.href='logout.php'">Logout</button>
                    _END;
                }
                else{
                    echo <<< _END
                        <button type="submit" onclick="window.location.href='validate.html'" >Login</button>
                    _END;
                }

                require_once 'login.php';
                $numOfPostPerPage = 5;

                if(isset($_SESSION['loggedIn']) && $_SESSION['loggedIn'] == true){
                    echo <<< _END
                        <!-- remove hardcoded links -->
                        <button type="submit" onclick="window.location.href= 'validate.php'";>Post</button>
                        <button type="submit" onclick="window.location.href= 'filter.html'";>Filter</button>
                    _END;
                }
                else {
                    echo <<< _END
                        <!-- remove hardcoded links -->
                        <button type="submit" onclick="window.location.href= 'validate.html'";>Post</button>
                        <button type="submit" onclick="window.location.href= 'filter.html'";>Filter</button>

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


                if(!$query)
                    die('Some error occured while fetching data.'.mysqli_error($connection));
                $num_of_rows = mysqli_num_rows($query);

                // echo "Number of rows found : ".$num_of_rows." with query "."<br/>";

                echo '<div class="row">';
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
                            <div class="row">
                                <div class="row m-3 text-center">
                                    <h2 class="text-center"> $i. $title : </h2>
                                </div>
                                <div class="row mx-3">
                                    <div class="col-4">
                                        <img src="./pics/$pic" class="img-fluid m-3">
                                    </div>
                                    <div class="col-8 p-3">
                                        <div class="row p-3 text-center">
                                            <h5> By : $author</h5>
                                        </div>
                                        <p class="p-3 text-center"> $content </p>
                                        <div class="row p-3">
                                            <h6> Dated : $date <br/></h6>
                                        </div>
                                        <form action='delete_post.php' method='post'>
                                            <input type="hidden" name="delete_author" value='$author'>
                                            <input type="hidden" name="delete_title" value='$title'>
                                            <input type="hidden" name="delete_content" value='$content'>
                                            <input type="hidden" name="delete_date" value='$date'>
                                            <input type='submit' value="Delete" class="float-right">
                                        </form>
                                    </div>
                                </div>              
                                <div class="form-group col-12">
                                    <hr>
                               </div>
                            </div>               
                            
                        _END;
                    }
                echo '</div>';

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

        </div>


    <script src="https://code.jquery.com/jquery-3.3.1.slim.min.js" integrity="sha384-q8i/X+965DzO0rT7abK41JStQIAqVgRVzpbzo5smXKp4YfRvH+8abtTE1Pi6jizo" crossorigin="anonymous"></script>
    <script src="https://cdnjs.cloudflare.com/ajax/libs/popper.js/1.14.7/umd/popper.min.js" integrity="sha384-UO2eT0CpHqdSJQ6hJty5KVphtPhzWj9WO1clHTMGa3JDZwrnQq4sF86dIHNDz0W1" crossorigin="anonymous"></script>
    <script src="https://stackpath.bootstrapcdn.com/bootstrap/4.3.1/js/bootstrap.min.js" integrity="sha384-JjSmVgyd0p3pXB1rRibZUAYoIIy6OrQ6VrjIEaFf/nJGzIxFDsf4x0xIM+B07jRM" crossorigin="anonymous"></script>
</body>
</html>

