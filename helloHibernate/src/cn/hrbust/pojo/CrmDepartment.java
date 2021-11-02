package cn.hrbust.pojo;

import java.util.HashSet;
import java.util.Set;

public class CrmDepartment {
  private int depId;
  private String depName;
  private Set<CrmPost> crmPosts = new HashSet<CrmPost>();

  public int getDepId() {
    return depId;
  }

  public void setDepId(int depId) {
    this.depId = depId;
  }

  public String getDepName() {
    return depName;
  }

  public void setDepName(String depName) {
    this.depName = depName;
  }

  public Set<CrmPost> getCrmPosts() {
    return crmPosts;
  }

  public void setCrmPosts(Set<CrmPost> crmPosts) {
    this.crmPosts = crmPosts;
  }

  public CrmDepartment(int depId, String depName, Set<CrmPost> crmPosts) {
    super();
    this.depId = depId;
    this.depName = depName;
    this.crmPosts = crmPosts;
  }
  public CrmDepartment() {
    super();
  }

  public String toString(){
    return "CrmDepartment [depID=" + depId + ",depName=" + depName ;
  }
}
