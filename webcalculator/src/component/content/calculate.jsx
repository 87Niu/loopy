import React, { Component } from 'react'
import BaseView from './baseView';
import DigitButton from './calculator/digitButton';
import { connect } from 'react-redux';
import ACTIONS from '../../reduex/action';
import OperationButton from './calculator/operationButton';

class Calculate extends Component {
    state = {
        formater: Intl.NumberFormat('en-us')
    };

    format = number => {
        if (number === "") return "";
        const [integer, decimal] = number.split('.');
        if (decimal === undefined)
            return this.state.formater.format(integer);
        return `${this.state.formater.format(integer)}.${decimal}`
    }

    render() {
        return (
            <React.Fragment>
                <BaseView>
                    <div className="calculator">
                        <div className="output">
                            <div className="lastput">{this.format(this.props.lastOperand)} {this.props.operation}</div>
                            <div className="currentput">{this.format(this.props.currentOperand)}</div>
                        </div>
                        <button onClick={this.props.clear} className='AC'>AC</button>
                        <button onClick={this.props.delete_digit}>DEL</button>
                        <OperationButton operation={"÷"} />
                        <DigitButton digit="7" />
                        <DigitButton digit="8" />
                        <DigitButton digit="9" />
                        <OperationButton operation={"*"} />
                        <DigitButton digit="4" />
                        <DigitButton digit="5" />
                        <DigitButton digit="6" />
                        <OperationButton operation={"+"} />
                        <DigitButton digit="1" />
                        <DigitButton digit="2" />
                        <DigitButton digit="3" />
                        <OperationButton operation={"-"} />
                        <DigitButton digit="0" />
                        <DigitButton digit="." />
                        <button onClick={this.props.evaluate} className='EQU'>=</button>
                    </div>
                </BaseView>
            </React.Fragment>
        );
    }
}

const mapStateToProps = (state, props) => {
    return {
        currentOperand: state.currentOperand,
        lastOperand: state.lastOperand,
        operation: state.operation,
    }
}

const mapDispatchToProps = {
    delete_digit: () => {
        return {
            type: ACTIONS.DELETE_DIGIT,
        }
    },
    clear: () => {
        return {
            type: ACTIONS.CLEAR,
        }
    },
    evaluate: () => {
        return {
            type: ACTIONS.EVALUATE,
        }
    }


}

export default connect(mapStateToProps, mapDispatchToProps)(Calculate);