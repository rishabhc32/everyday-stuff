import React, { Component } from 'react';
import Theme  from './Theme';
import Button from '@material-ui/core/Button';

class App extends Component {
    render() {
        return(
            <div>
                <Button color="primary">MyPrimary</Button>
                <Button color="secondary">MySecondary</Button>
            </div>
        );
    }
}

export default Theme(App);
