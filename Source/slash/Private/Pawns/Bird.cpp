

#include "Pawns/Bird.h"
#include "Components/CapsuleComponent.h"
#include "Components/SkeletalMeshComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "Camera/CameraComponent.h"


ABird::ABird()
{

	PrimaryActorTick.bCanEverTick = true;

	Capsule= CreateDefaultSubobject<UCapsuleComponent>(TEXT("Capsule")); //创建一个胶囊组件，text参数是组件的名字
	Capsule->SetCapsuleHalfHeight(20.f);        //设置胶囊的高度为20
	Capsule->SetCapsuleRadius(15.f);          //设置胶囊的半径为10
	SetRootComponent(Capsule);                       //设置根组件为胶囊组件


	BirdMesh = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("BirdMesh")); //创建一个骨骼组件，text参数是组件的名字
	BirdMesh -> SetupAttachment(GetRootComponent()); //将骨骼组件挂载到胶囊组件上


	AutoPossessPlayer = EAutoReceiveInput::Player0; //设置自动控制玩家0

	SpringArm = CreateDefaultSubobject<USpringArmComponent>(TEXT("SpringArm")); //创建一个弹簧臂组件，text参数是组件的名字
	SpringArm->SetupAttachment(GetRootComponent()); //将弹簧臂组件挂载到胶囊组件上
	SpringArm->TargetArmLength = 300.f; //设置弹簧臂的长度为500

	ViewCamera = CreateDefaultSubobject<UCameraComponent>(TEXT("ViewCamera")); //创建一个摄像机组件，text参数是组件的名字
	ViewCamera->SetupAttachment(SpringArm); //将摄像机组件挂载到弹簧臂组件上
	ViewCamera->FieldOfView = 60.f; //设置摄像机的视角为60度


}


void ABird::BeginPlay()
{
	Super::BeginPlay();
	
}

void ABird::MoveForward(float Value)
{
	if ((Controller != nullptr) && (Value != 0.f)) {

		FVector Foreward = GetActorForwardVector(); //获取当前飞行物体的前向方向
		AddMovementInput(Foreward, Value); //向前移动

	}

}

void ABird::Turn(float Value)
{
	AddControllerYawInput(Value); //控制飞行物体的转向

}

void ABird::LookUp(float Value)
{
	AddControllerPitchInput(Value); //控制飞行物体的俯仰角度

}

void ABird::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}


void ABird::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	PlayerInputComponent->BindAxis(FName("MoveForward"), this, &ABird::MoveForward); //绑定按键“W”的按下和松开事件，并将事件处理函数设置为MoveForward函数
	PlayerInputComponent->BindAxis(FName("Turn"), this, &ABird::Turn); 
	PlayerInputComponent->BindAxis(FName("LookUp"), this, &ABird::LookUp); 
}

