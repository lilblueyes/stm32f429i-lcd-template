$designerDir = 'C:\TouchGFX\4.24.2\designer'

foreach ($name in @(
    'Utils.dll',
    'ApplicationEvents.dll',
    'MoreLinq.dll',
    'Newtonsoft.Json.dll',
    'TouchGFX.Images.dll',
    'TouchGFXDomainModel.dll',
    'Validator.dll',
    'TouchGFXDesigner.dll'
)) {
    [void][System.Reflection.Assembly]::LoadFrom((Join-Path $designerDir $name))
}

$loadSaveType = [Type]::GetType('TouchGFXDomainModel.LoadSave.LoadSave, TouchGFXDomainModel')
$result = $loadSaveType.GetMethod('Load', [Reflection.BindingFlags] 'Public, Static').Invoke(
    $null,
    @('C:\Users\Jocelyn\Documents\GitHub\stm32f429i-lcd-template\TouchGFX\stm32f429i-lcd-template.touchgfx', $false)
)

$content = $result.Content
$model = $content.Model
$app = $model.Application

$errorHandler = New-Object 'Validator.Errors.ErrorHandler'
$availableFactory = New-Object 'TouchGFXDesigner.Factories.AvailableAssetsFactory'
$availableImages = $availableFactory.Create($app.ImageCollection, $app.PresetImageCollection, $app.FullUiPath)
$validatorFactory = New-Object 'TouchGFXDesigner.Factories.DomainValidatorFactory'
$validator = $validatorFactory.CreateDomainValidator($errorHandler, $model, $availableImages)
[void]$validator.Run()

"HasSimulator=$($app.HasSimulator)"
"HasTarget=$($app.HasTarget)"
"HasTargetInternalFlash=$($app.HasTargetInternalFlash)"
"ErrorCount=$($errorHandler.Errors.Count)"

foreach ($item in $errorHandler.Errors) {
    foreach ($kv in $item.ErrorDic.GetEnumerator()) {
        foreach ($err in $kv.Value) {
            "MODEL=$($item.Model.Name) TYPE=$($item.Model.GetType().FullName) PROP=$($kv.Key) ERRORTYPE=$($err.Type) MSG=$($err.Message)"
        }
    }
}
