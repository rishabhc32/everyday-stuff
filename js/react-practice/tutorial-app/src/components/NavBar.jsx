import React from 'react';
import AppBar from '@material-ui/core/AppBar';
import Toolbar from '@material-ui/core/Toolbar';
import Typography from '@material-ui/core/Typography';

function NavBar() {
    return(
        <div>
            <AppBar position="fixed">
                <Toolbar>
                    <Typography variant="title" color="inherit">
                        React and Material-UI Sample APP
                    </Typography>
                </Toolbar>
            </AppBar>
        </div>
    );
}

export default NavBar;