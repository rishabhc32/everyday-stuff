import React from 'react';

import './Recorder.scss';
import microphone from './microphone.svg';

class Recorder extends React.Component {
    render() {
        return (
            <React.Fragment>
            <div className="columns is-centered is-mobile main-element">
                <div className="column is-full-mobile is-10-tablet is-8-desktop is-half-widescreen }">
                    <img alt="" src="http://www.ricoh-imaging.co.jp/english/products/q-s1/ex/img/bod_mainImg_01.jpg" />
                </div>
            </div>
            <div className="columns is-centered is-mobile">
                <div className="column is-narrow ">
                    <img alt="" src={microphone} style={{width:'3.2rem'}}/>
                </div> 
            </div>
           </React.Fragment>
        );
    }
}

export default Recorder;