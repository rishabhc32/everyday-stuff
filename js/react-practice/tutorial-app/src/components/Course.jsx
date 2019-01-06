import React from 'react';
import { Card, CardMedia, Typography, CardContent } from '@material-ui/core';

function Course(props) {
    const cardMediaStyle = {
        height: 0,
        paddingTop: '56.25%'
    }

    return(
        <div>
            { props.course ? (
                    <Card>
                        <CardMedia 
                            style={cardMediaStyle} 
                            image={props.course.fields.image.fields.file.url}
                            title={props.course.fields.title}
                        />
                        <CardContent>
                            <Typography gutterBottom variant="headline">
                                {props.course.fields.title}
                            </Typography>
                            <Typography component="p"> 
                                {props.course.fields.shortDescription}
                            </Typography>
                        </CardContent>
                    </Card>
                ) : null 
            }
        </div>
    );
}

export default Course;
