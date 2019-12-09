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

	<title>Document</title>
</head>
<body>

	<style>
		.footer {

		  bottom: 0;
		  width: 100%;
		  height: 60px;
		  padding-bottom: 0;
		  margin-bottom: 0;
		  /* Set the fixed height of the footer here */
		  line-height: 60px;
		  /* Vertically center the text there */
		  background-color: #708090;
		  /* Not required */
		}
	</style>

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
				<li class="nav-item">
					<a class="nav-link disabled" href="#" tabindex="-1" aria-disabled="true">Disabled</a>
				</li>
			</ul>
			<form class="form-inline my-2 my-lg-0" action="http://www.google.com">
				<!-- <input class="form-control mr-sm-2" type="search" placeholder="Search" aria-label="Search"> -->
				<button class="btn btn-outline-success my-2 my-sm-0" type="submit">Search</button>
			</form>
		</div>
	</nav>

	<div class="row m-0">
		<!-- To list recent posts -->
		<div class="col-md-4">
			<?php
				require_once "login.php";
				$conn = mysqli_connect($db_hostname, $db_user, $db_password, $db_database);

				if(!$conn)
					echo "Some Error occured. <br>";
				else{
					$post_query = "SELECT * FROM {$db_table_posts}";
					$post_query_result = mysqli_query($conn, $post_query);

					$num_of_rows = mysqli_num_rows($post_query_result);
					// echo $num_of_rows;
					echo "<ul class='list-group float-left mx-4'>";
					if($num_of_rows > 0){
						echo "<h3 class='mx-4 text-justify'><i class='fas fa-bookmark'></i> Recent Blogs : <br></h3> <hr>";
					}
					for($i=0;$i<min(7, $num_of_rows);$i++){
						$row = mysqli_fetch_row($post_query_result);
						// print_r($row);
						echo <<< _END
							<li class='list-group-item text-left list-group-item-action'>
								<a href="blog.php?page=0" class="p-auto text-info ">{$row[1]}</a>
							</li>
						_END;
					}
					echo "</ul>";
				}
			?>
		</div>
		<!-- End list posts -->

		<div class="col-md-8">
		<!-- Corousel -->
			<div class="bd-example">
				<div id="carouselExampleCaptions" class="carousel slide" data-ride="carousel">
					<ol class="carousel-indicators">
						<li data-target="#carouselExampleCaptions" data-slide-to="0" class="active"></li>
						<li data-target="#carouselExampleCaptions" data-slide-to="1"></li>
						<li data-target="#carouselExampleCaptions" data-slide-to="2"></li>
					</ol>
					<div class="carousel-inner">
						<div class="carousel-item active">
							<img src="images/img1.jpg" class="d-block w-100 h-auto img-fluid" alt="...">
							<div class="carousel-caption d-none d-md-block">
								<h5>First slide label</h5>
								<p>This stores details about first slide.</p>
							</div>
						</div>
						<div class="carousel-item">
							<img src="https://encrypted-tbn0.gstatic.com/images?q=tbn%3AANd9GcS5z-iaMTGVmNWGnnyaqOAuEl61eNq9od-vJes1SU1IxBE2Xcua" class="d-block w-100 h-auto img-fluid" alt="...">
							<div class="carousel-caption d-none d-md-block">
							  <h5>Second slide label</h5>
							  <p>Second way.</p>
							</div>
						</div>
						<div class="carousel-item">
							<img src="https://encrypted-tbn0.gstatic.com/images?q=tbn%3AANd9GcQ1eTiMQEOkL-laS6H7b4e2U60IgA9ER9nKxq9FU6WbrgGPqXBL" class="d-block w-100 h-auto img-fluid" alt="...">
							<div class="carousel-caption d-none d-md-block">
							<h5>Third slide label</h5>
							<p>Praesent commodo cursus magna, vel scelerisque nisl consectetur.</p>
						</div>
					</div>
				</div>
					<a class="carousel-control-prev" href="#carouselExampleCaptions" role="button" data-slide="prev">
					  <span class="carousel-control-prev-icon" aria-hidden="true"></span>
					  <span class="sr-only">Previous</span>
					</a>
					<a class="carousel-control-next" href="#carouselExampleCaptions" role="button" data-slide="next">
					  <span class="carousel-control-next-icon" aria-hidden="true"></span>
					  <span class="sr-only">Next</span>
					</a>
				</div>
			</div>
		<!-- Corousel End -->
		</div>
	</div>
	<div class="container-fluid">
		<div class="row">
			<footer id="sticky-footer" class="py-3 bg-dark text-white-50" style="bottom: 0; position: fixed; width: 100%; color: #e05ea0;">
		    	<div class="container text-center">
		    		<small>Copyright &copy; Your Website</small>
		    	</div>
			</footer>
		</div>
	</div>
	
<!--  -->
<!-- 	<div class="container">
		<form action="blog.php" method="GET" enctype="multipart/form-data">
			<button onclick="submit" name="page" value="0">Blog</button>
		</form>
	</div> -->



	<script src="https://code.jquery.com/jquery-3.3.1.slim.min.js" integrity="sha384-q8i/X+965DzO0rT7abK41JStQIAqVgRVzpbzo5smXKp4YfRvH+8abtTE1Pi6jizo" crossorigin="anonymous"></script>
	<script src="https://cdnjs.cloudflare.com/ajax/libs/popper.js/1.14.7/umd/popper.min.js" integrity="sha384-UO2eT0CpHqdSJQ6hJty5KVphtPhzWj9WO1clHTMGa3JDZwrnQq4sF86dIHNDz0W1" crossorigin="anonymous"></script>
	<script src="https://stackpath.bootstrapcdn.com/bootstrap/4.3.1/js/bootstrap.min.js" integrity="sha384-JjSmVgyd0p3pXB1rRibZUAYoIIy6OrQ6VrjIEaFf/nJGzIxFDsf4x0xIM+B07jRM" crossorigin="anonymous"></script>
</body>
</html>