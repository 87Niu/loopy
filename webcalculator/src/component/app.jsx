import React, { Component } from 'react'
import NavBar from './narBar';
import { Routes, Route, Navigate } from 'react-router-dom';
import Home from './content/home';
import Login from './content/login';
import Register from './content/register';
import $ from 'jquery'
import NotFound from './content/notFound';
import Calculate from './content/calculate'
class App extends Component {
    state = {
        is_login: false,
        username: ""
    }
    componentDidMount() {
        $.ajax({
            url: "https://app165.acapp.acwing.com.cn/calculator/get_status/",
            type: "get",
            success: resp => {
                console.log(resp);
                if (resp.result === "login") {
                    this.setState({
                        is_login: true,
                        username: resp.username,
                    });
                } else {
                    this.setState({
                        is_login: false,
                    })
                }
            }
        });
    }

    render() {
        return (
            <React.Fragment>
                <NavBar is_login={this.state.is_login} username={this.state.username} />
                <div className="container">
                    <Routes>
                        <Route path='/calculator' element={<Home />} />
                        <Route path='/calculator/home' element={<Home />} />
                        <Route path='/calculator/calculate' element={<Calculate />} />
                        <Route path='/calculator/login' element={this.state.is_login ? <Navigate replace to="/calculator" /> : <Login />} />
                        <Route path='/calculator/register' element={this.state.is_login ? <Navigate replace to="/calculator" /> : <Register />} />
                        <Route path='/calculator/404' element={<NotFound />} />
                        <Route path='/calculator/*' element={<Navigate replace to={"/404"} />} />
                    </Routes>
                </div>
            </React.Fragment>
        );
    }
}

export default App;