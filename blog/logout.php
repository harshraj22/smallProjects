<?php
    session_start();
    $_SESSION['loggedIn'] = false;
    echo <<< _END
        <script type="text/javascript" >history.go(-1);</script>
    _END;

?>