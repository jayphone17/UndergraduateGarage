package domain;

import java.util.Date;

public class Plan {
    private Integer Plid;//主键
    private String Pltitle;//标题
    private Integer Plfatherid;//前置任务
    private Integer Plboolean;//是否审核0没审核 1 已审核
    private Integer Fid;//项目功能，外键
    private Integer Plsate;//状态
    private Integer Plpriority;//优先级
    private Integer Plperformance;//发送状态0未发送1已经发送
    private String Plplanstartdate;//计划开始时间
    private String Plplanfinishdate;//计划结束时间
    private String Plrealstartdate;//实际开始时间
    private String Plrealfinishdate;//实际结束时间
    private String Plcontent;//备注
    private Integer Usidexecute;//执行人,外键（关联用户表）
    private Integer Usidcharge;//负责人,外键（关联用户表）

}
