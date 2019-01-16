import React, { Component } from 'react';
import {Route, Link} from 'react-router-dom';
import logo from './logo.svg';
import './App.css';

const Courses = ({match}) => (
    <div>
        <ul>
            <li><Link to={`${match.url}/technology`}>Technology</Link></li>
            <li><Link to={`${match.url}/business`}>Business</Link></li>
            <li><Link to={`${match.url}/economics`}>Economics</Link></li>
        </ul>

        <Route 
            exact
            path={`${match.path}/technology`}
            render={() => (<div>This is technology</div>)}
        />
        <Route 
            path={`${match.path}/business`}
            component={() => (<div>This is business</div>)}
        />
        <Route 
            path={`${match.path}/economics`}
            render={() => (<div>This is economics</div>)}
        />
    </div>
);

const Home = () => (
    <div>
        <h2>Home</h2>
    </div>
);

const Airport = () => (
    <div>
        <ul>
            <li>Indira Gandhi International Airpot</li>
            <li>Chhatrapati Shivaji International Airport</li>
            <li>Kempegowda International Airport</li>
        </ul>
    </div>
);

const City = () => (
    <div>
        <ul>
            <li>Delhi</li>
            <li>Mumbai</li>
            <li>Bengaluru</li>
        </ul>
    </div>
);

class App extends Component {
    render() {
        return (
            <div>
                <ul>
                    <li><Link to="/">Home</Link></li>
                    <li><Link to="/courses">Courses</Link></li>
                    <li><Link to="/cities">Cities</Link></li>
                </ul>

                <Route path="/"  exact component={Home} />
                <Route path="/courses" component={Courses} />
                <Route path="/cities" component={City} />
            </div>
        );
    }
}

export default App;
