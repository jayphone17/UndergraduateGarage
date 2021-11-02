package cn.hrbust.pojo;

import java.util.HashSet;
import java.util.Set;

public class CrmLessontype {
  private int lessonTypeId;
  private Double lessonCost;
  private int total;
  private String lessonName;
  private String remark;
  private Set<CrmClass> crmClasses = new HashSet<CrmClass>();

  public int getLessonTypeId() {
    return lessonTypeId;
  }

  public void setLessonTypeId(int lessonTypeId) {
    this.lessonTypeId = lessonTypeId;
  }

  public Double getLessonCost() {
    return lessonCost;
  }

  public void setLessonCost(Double lessonCost) {
    this.lessonCost = lessonCost;
  }

  public int getTotal() {
    return total;
  }

  public void setTotal(int total) {
    this.total = total;
  }

  public String getLessonName() {
    return lessonName;
  }

  public void setLessonName(String lessonName) {
    this.lessonName = lessonName;
  }

  public String getRemark() {
    return remark;
  }

  public void setRemark(String remark) {
    this.remark = remark;
  }

  public Set<CrmClass> getCrmClasses() {
    return crmClasses;
  }

  public void setCrmClasses(Set<CrmClass> crmClasses) {
    this.crmClasses = crmClasses;
  }

  public CrmLessontype() {
    super();
  }
  public CrmLessontype(int lessonTypeId, Double lessonCost, Integer total,
                       String lessonName, String remark, Set<CrmClass> crmClasses) {
    super();
    this.lessonTypeId = lessonTypeId;
    this.lessonCost = lessonCost;
    this.total = total;
    this.lessonName = lessonName;
    this.remark = remark;
    this.crmClasses = crmClasses;
  }

  public String toString(){
    return "CrmLessonType [课程类型编号：" + lessonTypeId + ",课程开销：：" + lessonCost + ",总学时：" + total +
      ",课程名称：" + lessonName + ",注释：" + remark;
  }
}
