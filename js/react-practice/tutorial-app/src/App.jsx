import React, { Component } from 'react';
import NavBar from './components/NavBar.jsx'
import CourseList from './components/CourseList.jsx';
import './index.css'

class App extends Component {
    render() {
        return (
            <div>
                <NavBar />
                <CourseList />
            </div>
        );
    }
}

export default App;
