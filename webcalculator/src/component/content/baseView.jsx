import React, { Component } from 'react'

class BaseView extends Component {
    state = {}
    render() {
        return (
                <div className="container" style={{ marginTop: "20px" }}>
                    <div className="card">
                        <div className="card-body">
                            {this.props.children}
                        </div>
                    </div>
                </div>
        );
    }
}

export default BaseView;