import React, {Component} from 'react';
import { TextField, Grid } from '@material-ui/core';
import Course from './Course.jsx';
import * as contentful from 'contentful';

class CourseList extends Component {
    constructor() {
        super();

        this.state = {
            courses: [],
            searchString: ''
        }

        const client = contentful.createClient({
            space: 'z9hohbdredwz',
            accessToken: '22da92ed7015864189bda95249ba56024bf42d0e2fdaf278e64c8ae87ca08c2d'
        });

        this.client = client;
        this.getCourses();
    }

    getCourses = () => {
        const client = this.client;

        client.getEntries({
            content_type: 'course',
            query: this.state.searchString
        })
        .then(res => {
            this.setState({courses: res.items});
        })
        .catch(err => {
            console.log(err)
        })
    }

    onSearchInputChange = (event) => {
        event.target.value 
            ? this.setState({searchString: event.target.value})
            : this.setState({searchString: ''})
        
            this.getCourses();
    }

    render() {
        const textFeildStyle = {
            padding: 24
        }

        return(
            <div>
                { this.state.courses 
                    ? (
                        <div>
                            <TextField 
                                style={textFeildStyle}
                                id="searchInput"
                                placeholder="Search for Courses"
                                margin="normal"
                                onChange={this.onSearchInputChange}
                            />
                            <Grid container spacing={24} style={textFeildStyle}>
                                {
                                    this.state.courses.map((currentCourse, index) => {
                                        return(
                                            <Grid item xs={12} lg={4} xl={3} key={index}>
                                                <Course course={currentCourse} />
                                            </Grid>
                                        );
                                    })
                                }
                            </Grid>
                        </div>
                    )
                    : "No Course Found"
                }
            </div>
        );
    }
}

export default CourseList;
