import React, { Component } from 'react'
import BaseView from './baseView';

class NotFound extends Component {
    state = {  } 
    render() { 
        return (
            <React.Fragment>
                <BaseView>404</BaseView>
            </React.Fragment>
        );
    }
}
 
export default NotFound;