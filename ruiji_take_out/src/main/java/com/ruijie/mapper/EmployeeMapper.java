package com.ruijie.mapper;

import com.baomidou.mybatisplus.core.mapper.BaseMapper;
import com.ruijie.pojo.Employee;
import org.apache.ibatis.annotations.Mapper;


@Mapper
public interface EmployeeMapper extends BaseMapper<Employee> {
}
