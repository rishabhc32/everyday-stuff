import React, { Component } from 'react';
import {BrowserRouter as Router, Route, Link} from 'react-router-dom';
import './App.css';
import Redirect from 'react-router-dom/Redirect';

const Public = () => (
    <div> This is a public page </div>
);

const Private = () => (
    <div> This is private page </div>
);

const Login = () => (
    <div> Login Page <button>login</button> </div>
);

const AuthService = {
    isAuthenticated: false,
    authenticate(cb) {
        this.authenticate = true;
        setTimeout(cb, 100);
    },
    logout(cb) {
        this.isAuthenticated = false;
        setTimeout(cb, 100);
    }
}

const SecretRoute = ({component: Component}, ...rest) => (
    <Route {...rest} render={(props) => (
        AuthService.isAuthenticated === true
            ? <Component {...props} />
            : <Redirect to="/login" />
    )}
    
    />
);

class App extends Component {
    render() {
        return (
            <Router>
                <div style={{width: 1000, margin: "0 auto"}}>
                    <ul>
                        <li><Link to="/public">Public</Link></li>
                        <li><Link to="/private">Private</Link></li>
                    </ul>

                    <hr />

                    <Route path="/public" component={Public} />
                    <SecretRoute path="/private" component={Private} />
                </div>
            </Router>
        );
    }
}

export default App;
