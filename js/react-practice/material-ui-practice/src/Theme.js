import React from 'react';
import {MuiThemeProvider, createMuiTheme} from '@material-ui/core';
import purple from '@material-ui/core/colors/purple';

const theme = createMuiTheme({
    palette: {
        primary: {main: purple[500]},
        secondary: {main: "#11cb5f"},
    },
    typography: {useNextVariants: true},
});

function myTheme(Component) {
    function Theme() {
        return(
            <MuiThemeProvider theme={theme}>
                <Component />
            </MuiThemeProvider>
        ); 
    }

    return Theme;
}

export default myTheme;
