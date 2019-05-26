import React from 'react';
import { BrowserRouter as Router, Route } from 'react-router-dom';

import StartPage from './StartPage';
import Recoder from './Recorder';

function App() {
    return (
        <Router>
            <Route exact path="/" component={StartPage} />
            <Route exact path="/start" component={Recoder} />
        </Router >
    );
}

export default App;
