
// All project specific code and assets belong to Magnus Elden unless otherwise specified. You are free to alter and use this project for education, research and other non-commercial uses. Commercial use requires a written permit from the owner(s).

#include "ViveTest.h"
#include "VTKRenderingThread.h"

//
// DumpXMLFile - report on the contents of an XML or legacy vtk file
//  Usage: DumpXMLFile XMLFile1 XMLFile2 ...
//         where
//         XMLFile is a vtk XML file of type .vtu, .vtp, .vts, .vtr,
//         .vti, .vto 
//
#include <vtkSmartPointer.h>
#include <vtkXMLReader.h>
#include <vtkXMLUnstructuredGridReader.h>
#include <vtkXMLPolyDataReader.h>
#include <vtkXMLStructuredGridReader.h>
#include <vtkXMLRectilinearGridReader.h>
#include <vtkXMLHyperOctreeReader.h>
#include <vtkXMLCompositeDataReader.h>
#include <vtkXMLStructuredGridReader.h>
#include <vtkXMLImageDataReader.h>
#include <vtkDataSetReader.h>
#include <vtkDataSet.h>
#include <vtkUnstructuredGrid.h>
#include <vtkRectilinearGrid.h>
#include <vtkHyperOctree.h>
#include <vtkImageData.h>
#include <vtkPolyData.h>
#include <vtkStructuredGrid.h>
#include <vtkPointData.h>
#include <vtkCellData.h>
#include <vtkFieldData.h>
#include <vtkCellTypes.h>
#include <vtksys/SystemTools.hxx>
#include <vtkVersion.h>
#include <vtkSmartPointer.h>
#include <vtkSphere.h>
#include <vtkSampleFunction.h>
#include <vtkSmartVolumeMapper.h>
#include <vtkColorTransferFunction.h>
#include <vtkPiecewiseFunction.h>
#include <vtkVolumeProperty.h>
#include <vtkImageShiftScale.h>
#include <vtkImageData.h>
#include <vtkPointData.h>
#include <vtkDataArray.h>
#include <vtkXMLImageDataReader.h>
#include <vtkCutter.h>
#include <map>

#include <vtkInteractorStyleTrackballCamera.h>
#include <vtkSmartPointer.h>
#include <vtkXMLPolyDataReader.h>
#include <vtkPolyDataMapper.h>
#include <vtkPolyData.h>
#include <vtkPointData.h>
#include <vtkPlane.h>
#include <vtkProperty.h>
#include <vtkActor.h>
#include <vtkCamera.h>
#include <vtkRenderer.h>
#include <vtkRenderWindow.h>
#include <vtkRenderWindowInteractor.h>
#include <vtkLookupTable.h>
#include <vtkRenderLargeImage.h>
#include <vtkPNGWriter.h>

#include <GLEW/glew.h>

//***********************************************************
//Thread Worker Starts as NULL, prior to being instanced
//		This line is essential! Compiler error without it
VTKRenderingThread* VTKRenderingThread::Runnable = nullptr;
//***********************************************************

VTKRenderingThread::VTKRenderingThread()
{
	Thread = FRunnableThread::Create(this, TEXT("VTKRenderingThread"), 0, TPri_BelowNormal); //windows default = 8mb for thread, could specify more
	finished = false;
}

VTKRenderingThread::~VTKRenderingThread()
{
	delete Thread;
	Thread = NULL;
}

//Init
bool VTKRenderingThread::Init()
{

	/*
	if (GLEW_OK == glewInit()) {
		UE_LOG(LogTemp, Warning, TEXT("GLEW worked"));
	} else {
		UE_LOG(LogTemp, Warning, TEXT("GLEW failed"));
	}


	GLfloat verts[] =
	{
		+0.0f, +1.0f,
		-1.0f, -1.0f,
		+1.0f, -1.0f,
	};
	GLuint myBufferID;
	glGenBuffers(1, &myBufferID);
	glBindBuffer(GL_ARRAY_BUFFER, myBufferID);
	glBufferData(GL_ARRAY_BUFFER, sizeof(verts),
		verts, GL_STATIC_DRAW);
	glEnableVertexAttribArray(0);
	glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 0, 0);*/
	return true;
}

//Run
uint32 VTKRenderingThread::Run()
{
	//Initial wait before starting
	FPlatformProcess::Sleep(0.03);

	//While not told to stop this thread 
	//		and not yet finished finding Prime Numbers
	while (!IsFinished()) {

	/*	glViewport(0, 0, 600, 600);
		glDrawArrays(GL_TRIANGLES, 0, 3);
*/
		
		//finished = true;
		FPlatformProcess::Sleep(0.01);
	}

	GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Red, "Finished the thread. ");
	//Run FPrimeNumberWorker::Shutdown() from the timer in Game Thread that is watching
	//to see when FPrimeNumberWorker::IsThreadFinished()

	return 0;
}

//stop
void VTKRenderingThread::Stop()
{

}

void VTKRenderingThread::EnsureCompletion()
{
	Stop();
	Thread->WaitForCompletion();
}

void VTKRenderingThread::Shutdown()
{
	if (Runnable) {
		Runnable->EnsureCompletion();
		delete Runnable;
		Runnable = NULL;
	}
}

bool VTKRenderingThread::IsThreadFinished()
{
	if (Runnable) return Runnable->IsFinished();
	return true;
}

VTKRenderingThread* VTKRenderingThread::StaticInit()
{
	//Create new instance of thread if it does not exist
	//		and the platform supports multi threading!
	if (!Runnable && FPlatformProcess::SupportsMultithreading()) {
		Runnable = new VTKRenderingThread();
	}
	return Runnable;
}
