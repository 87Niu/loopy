package com.ruijie.common;


import lombok.extern.slf4j.Slf4j;
import org.springframework.stereotype.Controller;
import org.springframework.web.bind.annotation.*;

import java.sql.SQLIntegrityConstraintViolationException;


/* 全局异常处理*/
@ControllerAdvice(annotations = {RestController.class, Controller.class})
@ResponseBody
public class GlobalExceptionHandler {

    @ExceptionHandler(SQLIntegrityConstraintViolationException.class)
    public R<String> exceptionHandler(SQLIntegrityConstraintViolationException e) {
        if (e.getMessage().contains("Duplicate entry")) {
            String[] split = e.getMessage().split(" ");
            String  msg = split[2] + "已存在";
            return R.error(msg);
        }
        return R.error("未知错误");
    }


    @ExceptionHandler(CustomException.class)
    public R<String> exceptionHandler(CustomException ex){

        return R.error(ex.getMessage());
    }
}
