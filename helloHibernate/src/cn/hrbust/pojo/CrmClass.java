package cn.hrbust.pojo;

import java.util.Date;

public class CrmClass {
  private int classId;
  private String name;
  private Date beginTime;
  private Date endTime;
  private int totalCount;
  private int goCount;
  private int leaveCount;
  private CrmLessontype crmLessontype;

  public int getClassId() {
    return classId;
  }

  public void setClassId(int classId) {
    this.classId = classId;
  }

  public String getName() {
    return name;
  }

  public void setName(String name) {
    this.name = name;
  }

  public Date getBeginTime() {
    return beginTime;
  }

  public void setBeginTime(Date beginTime) {
    this.beginTime = beginTime;
  }

  public Date getEndTime() {
    return endTime;
  }

  public void setEndTime(Date endTime) {
    this.endTime = endTime;
  }

  public int getTotalCount() {
    return totalCount;
  }

  public void setTotalCount(int totalCount) {
    this.totalCount = totalCount;
  }

  public int getGoCount() {
    return goCount;
  }

  public void setGoCount(int goCount) {
    this.goCount = goCount;
  }

  public int getLeaveCount() {
    return leaveCount;
  }

  public void setLeaveCount(int leaveCount) {
    this.leaveCount = leaveCount;
  }

  public CrmLessontype getCrmLessontype() {
    return crmLessontype;
  }

  public void setCrmLessontype(CrmLessontype crmLessontype) {
    this.crmLessontype = crmLessontype;
  }

  public CrmClass(int classId, CrmLessontype crmLessontype, String name,
                  Date beginTime, Date endTime, int totalCount,
                  int goCount, int leaveCount) {
    super();
    this.classId = classId;
    this.crmLessontype = crmLessontype;
    this.name = name;
    this.beginTime = beginTime;
    this.endTime = endTime;
    this.totalCount = totalCount;
    this.goCount = goCount;
    this.leaveCount = leaveCount;
  }

  public CrmClass(){
    super();
  }

  public String toString(){
    return "CrmClass [课程编号：" + classId + ",课程名称：：" + name + ",开课时间：" + beginTime + ",结课时间：" + endTime + ",上课人数：" + totalCount
      + ",出勤人数：" + goCount + ",缺勤人数：" + leaveCount;
  }
}
