import React from 'react';
import {Link} from 'react-router-dom';
import './StartPage.scss';

import icon from './icon.svg';

const descriptionText = `Imporve your public speaking through automated AI tests. Speeks lets you record your speech and analyze it using state of art Machine Learning Algorithms. It rates the quality of your speech based on parameters like Grammar check, Speech emotion, Confidence level, etc.` ;

function StartPage() {
    return (
        <React.Fragment>
        <nav className="navbar has-shadow">
            <div className="navbar-brand nav-text-icon">
                <img className="navbar-item" src={icon} alt="" />
                <span>
                    Speeks
                </span>
            </div>
        </nav>

        <section className="hero">
            <div className="hero-body has-text-centered">
                <h1 className="title is-1 hero-title">
                    Speeks
                </h1>
                
                <div className="columns is-centered hero-subtitle-container">
                    <h2 className="subtitle column is-half-desktop ">
                        {descriptionText}
                    </h2>
                </div>
                <div className="columns is-centered start-button-container">
                    <Link to='/start' className="button is-primary">Start!</Link>
                </div>
            </div>
        </section>
        </React.Fragment>
    );
}

export default StartPage;