<?php
    session_start();
?>

<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <meta http-equiv="X-UA-Compatible" content="ie=edge">
    <link rel="stylesheet" href="https://stackpath.bootstrapcdn.com/bootstrap/4.3.1/css/bootstrap.min.css" integrity="sha384-ggOyR0iXCbMQv3Xipma34MD+dH/1fQ784/j6cY/iJTQUOhcWr7x9JvoRxT2MZw1T" crossorigin="anonymous">
    <link rel="stylesheet" href="https://use.fontawesome.com/releases/v5.7.0/css/all.css" integrity="sha384-lZN37f5QGtY3VHgisS14W3ExzMWZxybE1SJSEsQp9S+oqd12jhcu+A56Ebc1zFSJ" crossorigin="anonymous">

    <title>Post</title>
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
                    <a class="nav-link" href="validate.html">Login</a>
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
                <li class="nav-item">
                    <a class="nav-link disabled" href="#" tabindex="-1" aria-disabled="true">Disabled</a>
                </li>
            </ul>
            <form class="form-inline my-2 my-lg-0">
                <input class="form-control mr-sm-2" type="search" placeholder="Search" aria-label="Search">
                <button class="btn btn-outline-success my-2 my-sm-0" type="submit">Search</button>
            </form>
        </div>
    </nav>

    <div class="jumbotron">
        <?php
        // add next and prev button, display only 5 posts per page (don't hardcode)
            require_once 'login.php';
            $connection = mysqli_connect($db_hostname,$db_user,$db_password,$db_database);

            if(!$connection){
                die('Couldnt connect to database. <br/>'.mysqli_connect_error($connection));
            }

            $result = 0;

            if(empty($_POST['author_name'])==true && empty($_POST['post_date'])==true){
                die("<br><h3 class='text-center'>Empty data. </h3><br>");
            }
            else if(empty($_POST['post_date'])==true){
                $query = "SELECT * FROM ".$db_table_posts." WHERE author = '".$_POST['author_name']."'";
                $result = mysqli_query($connection,$query);
            }
            else if(empty($_POST['author_name'])==true){
                $query = "SELECT * FROM {$db_table_posts} WHERE day = '{$_POST['post_date']}'";
                $result = mysqli_query($connection,$query);
            }
            else {
                $query = "SELECT * FROM {$db_table_posts} WHERE day = '{$_POST['post_date']}' AND author = '{$_POST['author_name']}'";
                $result = mysqli_query($connection,$query);
            }

            if(!$result){
                die('Error while searching.'.mysqli_error($connection));
            }

            $numRows = mysqli_num_rows($result);

            echo '<div class="row m-4 p-4">';
                for($i=0;$i<$numRows;$i++){
                    $rows = mysqli_fetch_row($result);

                    $pic = '';
                    if(isset($rows[5]))
                        $pic = $rows[5];

                    $author = $rows[0];
                    $title = $rows[1];
                    $content = $rows[2];
                    $date = $rows[3];

                    echo <<< _END
                        <div class="row">
                            <div class="row p-2">
                                <h1> $title </h1>
                            </div>
                            <p></p>
                            <div class="row p-2">
                                <h5> By : $author</h5>
                            </div>
                            <div class="row p-2">
                                <img src="./pics/$pic" class="col-md-4 img-fluid width-100 height-auto">
                            </div>
                            <p class="row">
                                <h6> $content </h6>
                                <br>
                            </p>
                            <h6> Dated : $date <br></h6>
                            <hr><br>
                            <span class="border-top my-3"></span>
                        </div>
                    _END;
                }
            echo '</div>';

            if($numRows == 0){
                echo "No data matched for this input <br/>";
            }
        ?>
    </div>

</body>
</html>
