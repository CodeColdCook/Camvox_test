#include <thread>

#include "common.h"
#include "Calibrating.h"

using namespace Camvox;

std::thread *mptCalibrating;
const string strSettingPath = "/home/cbreezy/002_everything_here/104-CamVox-test/Camvox_calibr_test1/config/camera.yaml";
Calibrating *mpCalibratingter;

pcl::PointCloud<pcl::PointXYZI>::Ptr horizon_cloud__;

bool tloadPcd(const std::string &pcd_file)
  {
    cout << "start load pcd file... " << endl;
    horizon_cloud__ = pcl::PointCloud<pcl::PointXYZI>::Ptr(new pcl::PointCloud<pcl::PointXYZI>);
    if (pcl::io::loadPCDFile(pcd_file, *horizon_cloud__) != -1)
    {
      std::cout << "load pcd file successfully! size:" << horizon_cloud__->points.size() << std::endl;
      return true;
    }
    else
    {
      std::cout << "failed to load pcd file" << std::endl;
      return false;
    }
  }


int main()
{
    cout << "camvox" << endl;
    mpCalibratingter = new Calibrating(strSettingPath);

    // to run
    mpCalibratingter->cumulative_flag = true;
    mpCalibratingter->RGBPath = "/home/cbreezy/002_everything_here/104-CamVox-test/Camvox_calibr_test1/calibration/calibration.jpg";
    mpCalibratingter->PcdPath = "/home/cbreezy/002_everything_here/104-CamVox-test/Camvox_calibr_test1/calibration/calibration.pcd";
    // mpCalibratingter->projectionType = "depth";
    // mpCalibratingter->color2dDepth = true;
    mpCalibratingter->projectionType = "intensity";
    mpCalibratingter->color2dDepth = false;
    
    // mptCalibrating = new thread(&Camvox::Calibrating::Run, mpCalibratingter);
    mpCalibratingter->Run();

    // horizon_cloud__ = pcl::PointCloud<pcl::PointXYZI>::Ptr(new pcl::PointCloud<pcl::PointXYZI>);
    // string pcd_path = "/home/cbreezy/002_everything_here/104-CamVox-test/Camvox_calibr_test1/calibration/calibration.pcd";
    // tloadPcd(pcd_path);



    return 0;
}